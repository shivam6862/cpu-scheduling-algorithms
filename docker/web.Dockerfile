# Stage 1: Building the app
FROM node:20-alpine AS base

# Set the working directory
WORKDIR /web

# Copy package.json and package-lock.json
COPY ./web/package.json ./package.json
COPY ./web/package-lock.json ./package-lock.json
# Install dependencies
RUN npm install

# Copy the rest of the application code
COPY ./web .

# local environment setup
FROM base AS local
ENV NEXT_PUBLIC_BACKEND_URL=http://127.0.0.1:5000

# production environment setup
FROM base AS production
ENV NEXT_PUBLIC_BACKEND_URL=http://api:5000

# Build the application
RUN npm run build

# Expose the port the app runs on
EXPOSE 3000

# Run the web service
ENTRYPOINT npm start