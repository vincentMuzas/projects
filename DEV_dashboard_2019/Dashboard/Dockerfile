FROM node:12.2-alpine
#FROM  angular:9.1.1

# App directory
RUN mkdir -p /usr/src/app/dashboard

# Change workspace
WORKDIR /usr/src/app/dashboard

# Copy dependencies
COPY package.json /usr/src/app/dashboard

# install dependencies
RUN npm install -g @angular/cli

COPY . /usr/src/app/dashboard

# Port
EXPOSE 4200

CMD ["cd","/Dashboard"]

# Command to run server
CMD ["ng","serve","--open"]