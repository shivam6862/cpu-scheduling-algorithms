# Stage 1: Building the app
FROM python:3.12-slim AS base

# Install necessary system packages
RUN apt-get update && apt-get install -y \
    libpq-dev \
    gcc \
    g++ \
    pkg-config \
    libcairo2-dev \
    && rm -rf /var/lib/apt/lists/*

# Upgrade pip and setuptools
RUN pip install --upgrade pip setuptools

# Set the working directory
WORKDIR /app

# Copy the requirements file to the working directory
COPY ./api/requirements.txt .

# Install packages from requirements.txt
RUN pip install --no-cache-dir -r requirements.txt

# Copy the rest of the application code
COPY ./api .

# Add this line to copy the "algorithms" directory
COPY ./algorithms ./algorithms

# local environment setup
FROM base AS local
ENV PYTHON_ENV=local

# production environment setup
FROM base AS production
ENV PYTHON_ENV=production

# Expose the port the app runs on
EXPOSE 5000

# Run the app
ENTRYPOINT python main.py