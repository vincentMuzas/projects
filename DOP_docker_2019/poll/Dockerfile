FROM python:3.7-buster

EXPOSE 80

WORKDIR /project

COPY . /project

RUN pip install -r requirements.txt

CMD ["flask", "run", "--host=0.0.0.0", "--port=80"]