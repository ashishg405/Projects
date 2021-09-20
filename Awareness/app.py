from flask import Flask
from flask import request
from flask import Response
import json
import mysql.connector

app = Flask('Awareness')

Users_table_query = 'CREATE TABLE IF NOT EXISTS awareness.users ' \
                    '(name VARCHAR(30) NOT NULL,  ' \
                    'id INT NOT NULL AUTO_INCREMENT, ' \
                    'email VARCHAR(30), '\
                    'UNIQUE KEY (name), '\
                    'PRIMARY KEY (id))'
Questions_table_query = 'CREATE TABLE IF NOT EXISTS awareness.questions ' \
                        '(id INT NOT NULL AUTO_INCREMENT, ' \
                        'text BLOB, ' \
                        'answer ENUM("a", "b", "c", "d") ' \
                        'PRIMARY KEY (id))'
Options_table_query = 'CREATE TABLE IF NOT EXISTS awareness.options ' \
                      '(que_id INT, ' \
                      'text BLOB, ' \
                      'id ENUM("a", "b", "c", "d"), ' \
                      'FOREIGN KEY (que_id) REFERENCES awareness.questions (id) ' \
                      'PRIMARY KEY (que_id, id))'
conn = mysql.connector.connect(host = 'localhost', user = 'root', passwd = 'Ashish@123', database = 'awareness')
cur = conn.cursor()
cur.execute(Users_table_query)
conn.commit()

@app.route('/', methods = ['GET'])
def intro():
    return 'Hi, Welcome to Awareness App!'

@app.route('/create_user', methods = ['POST'])
def create_user():
    data = request.json
    nm = data['name']
    insert_query = f'INSERT INTO awareness.users (name) VALUES ("{nm}")'
    cur = conn.cursor()
    cur.execute(insert_query)
    conn.commit()
    search_query = f'SELECT id FROM awareness.users WHERE name = "{nm}"'
    cur.execute(search_query)
    id_list = cur.fetchall()
    u_id = id_list[0][0]
    '''dic = {'01':101}
    x = json.dumps(dic)
    print(x)
    y = json.loads(x)
    print(y==dic)'''
    dic = {'id':u_id}
    return Response(json.dumps(dic))

@app.route('/create_question', methods = ['GET'])
def questions_maker():
    que_data = request.json
    txt = que_data['text']
    opt_data = que_data[request.json]
