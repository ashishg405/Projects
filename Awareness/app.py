import MySQLdb.cursors
from flask import Flask, Response, request, jsonify
from flask_mysqldb import MySQL
import json
import uuid

app = Flask('Awareness')
app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = 'Ashish@123'
app.config['MYSQL_DB'] = 'awareness'
with app.app_context():
    mysql = MySQL(app)

    Users_table_query = 'CREATE TABLE IF NOT EXISTS awareness.users ' \
                        '(name VARCHAR(30) NOT NULL,  ' \
                        'id VARCHAR (100) NOT NULL, ' \
                        'email VARCHAR(30), '\
                        'PRIMARY KEY (id))'
    Questions_table_query = 'CREATE TABLE IF NOT EXISTS awareness.questions ' \
                            '(id VARCHAR(100) NOT NULL, ' \
                            'text BLOB, ' \
                            'answer ENUM("a", "b", "c", "d"), ' \
                            'PRIMARY KEY (id))'
    Options_table_query = 'CREATE TABLE IF NOT EXISTS awareness.options ' \
                          '(q_id VARCHAR (100), ' \
                          'text BLOB, ' \
                          'id ENUM("a", "b", "c", "d"), ' \
                          'FOREIGN KEY (q_id) REFERENCES awareness.questions (id), ' \
                          'PRIMARY KEY (q_id, id))'
    Response_table_query = 'CREATE TABLE IF NOT EXISTS awareness.response ' \
                           '(user_id VARCHAR (100), ' \
                           'question_id VARCHAR (100), ' \
                           'response ENUM("a", "b", "c", "d"), ' \
                           'FOREIGN KEY (user_id) REFERENCES awareness.users (id), ' \
                           'FOREIGN KEY (question_id) REFERENCES awareness.questions (id), ' \
                           'PRIMARY KEY (user_id, question_id))'
    Result_table_query = 'CREATE TABLE IF NOT EXISTS awareness.result ' \
                         '(user_id VARCHAR (100), ' \
                         'result INT, ' \
                         'FOREIGN KEY (user_id) REFERENCES awareness.response (user_id), ' \
                         'PRIMARY KEY (user_id))'
    conn = mysql.connection
    cur = conn.cursor()
    cur.execute(Users_table_query)
    cur.execute(Questions_table_query)
    cur.execute(Options_table_query)
    cur.execute(Response_table_query)
    cur.execute(Result_table_query)
    conn.commit()

@app.route('/', methods = ['GET'])
def intro():
    return 'Hi, Welcome to Awareness App!'

@app.route('/create_user', methods = ['POST'])
def create_user():
    data = request.json
    nm = data['name']
    id = str(uuid.uuid4())
    insert_query = f'INSERT INTO awareness.users (name, id) VALUES ("{nm}", "{id}")'
    cur = conn.cursor()
    cur.execute(insert_query)
    conn.commit()
    dic = {'id':id}
    return Response(json.dumps(dic))

@app.route('/create_question', methods = ['POST'])
def questions_maker():
    que_data = request.json
    txt = que_data['text']
    options = que_data['options']
    answer = que_data['answer']
    q_id = str(uuid.uuid4())
    insert_query_que = f'INSERT INTO awareness.questions (id, text, answer) VALUES ("{q_id}", "{txt}", "{answer}")'
    cur = conn.cursor()
    cur.execute(insert_query_que)
    conn.commit()
    for k,v in options.items():
        insert_query_opt = f'INSERT INTO awareness.options (q_id, text, id) VALUES ("{q_id}", "{v}", "{k}")'
        cur.execute(insert_query_opt)
    conn.commit()
    return "Done!"

@app.route('/get_questions', methods = ['GET'])
def get_questions():
    select_query = f'SELECT id, text FROM awareness.questions'
    cur = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
    cur.execute(select_query)
    return Response(json.dumps(cur.fetchall()))

@app.route('/question_details', methods = ['GET'])
def question_details():
    params = request.args
    que_id = params['question_id']
    select_query_questions = f'SELECT * FROM awareness.questions WHERE id = "{que_id}"'
    cur = conn.cursor(dictionary=True)
    cur.execute(select_query_questions)
    list_json1 = cur.fetchall()
    select_query_options = f'SELECT q_id, text, id FROM awareness.options WHERE q_id = "{que_id}"'
    cur.execute(select_query_options)
    list_json2 = cur.fetchall()
    op_json = {}
    opt_json = {}
    for x in list_json2:
        opt_json[str(x['id'])] = str(x['text'])
    op_json['text'] = str(list_json1[0]['text'])
    op_json['options'] = opt_json
    op_json['answer'] = str(list_json1[0]['answer'])
    return Response(json.dumps(op_json))

@app.route('/answer', methods = ['POST'])
def answer():
    params = request.args
    user_id = params['user_id']
    question_id = params['question_id']
    body = request.json
    response = body['ans']
    insert_query = f'INSERT INTO awareness.responses (user_id, question_id, response) ' \
                   f'VALUES ("{user_id}", "{question_id}", "{response}")'
    cur = conn.cursor()
    cur.execute(insert_query)
    conn.commit()
    return 'Done!'

@app.route('/result', methods = ['GET'])
def result():
    params = request.args
    user_id = params['user_id']
    select_query1 = f'SELECT question_id, response FROM awareness.response WHERE user_id = "{user_id}"'
    cur = conn.cursor(dictionary=True)
    cur.execute(select_query1)
    dict_response = cur.fetchall()
    result = 0
    no_of_que = 0
    for x in dict_response:
        select_query2 = f'SELECT answer FROM awareness.questions WHERE id = \"{x["question_id"]}\"'
        cur.execute(select_query2)
        dict_answer = cur.fetchall()
        no_of_que += 1
        if dict_answer['answer'] == x['response']:
            result += 1
    percentage = (result // no_of_que) * 100
    insert_query = f'INSERT INTO awareness.result (user_id, result) ' \
                   f'VALUES ("{user_id}", "{percentage}")'
    cur.execute(insert_query)
    select_query3 = f'SELECT count(*) FROM awareness.result WHERE result <= {percentage}'
    cur.execute(select_query3)
    print(cur.fetchall())
    return " "