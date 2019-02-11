import json
import sqlite3
from flask import Flask, request, g
from .utils import json_response, JSON_MIME_TYPE

app = Flask(__name__)

@app.before_request
def before_request():
	g.db = MySQLdb.connect(host="localhost",
							user="root", 
							passwd="root",
							db= app.config['DATABASE_NAME']