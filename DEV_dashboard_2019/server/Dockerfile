FROM  node:13.3-alpine

# App directory
RUN mkdir -p /usr/src/app

# Change workspace
WORKDIR /usr/src/app

# Copy dependencies
COPY package.json /usr/src/app

# install dependencies
RUN npm install

COPY . /usr/src/app

# Port
EXPOSE 8080

# Command to run server
CMD ["npm", "run","server"]