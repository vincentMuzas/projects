import os

#from .test.py import app

if __name__ == '__main__':
	app.debug = True
	app.config['DATABASE_NAME'] = 'job_board'
	host = os.environ.get('IP', '0.0.0.0')
	post = int(os.environ.get('PORT', 8080))
	print("host = ", host)
	print("post = ", post)