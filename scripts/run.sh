#!/bin/bash

# Navigate to the api folder
cd api

# Check if .venv does not exist
if [ ! -d ".venv" ]; then
  echo ".venv not found. Setting up the virtual environment..."
  # Assuming Python3. If specific version is needed, adjust accordingly.
  python3 -m venv .venv
    # Activate the virtual environment
    source .venv/bin/activate
    # Install dependencies if needed
    # This step assumes a requirements.txt file is present
    pip install -r requirements.txt
else
    # Activate the virtual environment
    source .venv/bin/activate
fi

# Run the Python application
python main.py &
PYTHON_PID=$!
echo "Python server started with PID: $PYTHON_PID"

# Navigate to the web folder
cd ../web

# Check if node_modules does not exist
if [ ! -d "node_modules" ]; then
  echo "node_modules not found. Installing dependencies..."
  npm install
fi

# Check if .next directory does not exist
if [ ! -d ".next" ]; then
  echo ".next not found. Building the project..."
  npm run build
fi

# Start the npm project
npm start &
NODE_PID=$!
echo "Node.js server started with PID: $NODE_PID"

# Wait for the Enter key
read -p "Press Enter to stop servers and deactivate environment..."

# deactivate virtual environment and stop Node.js server
echo "Stopping Python server..."
kill $PYTHON_PID
echo "Deactivating virtual environment..."
deactivate
echo "Stopping Node.js server..."
kill $NODE_PID

echo "Servers stopped and environment deactivated."
