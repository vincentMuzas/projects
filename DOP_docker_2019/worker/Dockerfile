FROM maven:3.5-jdk-8-alpine

WORKDIR /project

COPY . /project

RUN mvn dependency:resolve

RUN mvn package

WORKDIR /project/target

CMD [ "java", "-jar", "worker-jar-with-dependencies.jar" ]