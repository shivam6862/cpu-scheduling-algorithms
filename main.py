from flask import Flask, request, jsonify
import subprocess
import os
import flask_cors as cors
app = Flask(__name__)

cors.CORS(app)

@app.route('/run-code', methods=['GET'])
def run_code():
    # data = request.get_json()
    # data = data['data']
    
    # with open('data.txt', 'w') as f:
        # f.write(data)
            
    try:
        exe_file_name = 'output.exe'
        curr_file_path = '"' + os.path.abspath('main.cpp') + '"' + " " + '"' + os.path.abspath('1.FirstComeFirstServeAlgorithm/FirstComeFirstServe.cpp') + '"' + " " + '"' + os.path.abspath('2.ShortestJobFirstAlgorithm/ShortestJobFirstAlgorithm.cpp') + '"' + " " + '"' + os.path.abspath('3.RoundRobinAlgorithm/RoundRobinAlgorithm.cpp') + '"' + " " + '"' + os.path.abspath('4.PrioritySchedulingAlgorithms/PrioritySchedulingAlgorithms.cpp') + '"'
        command = "g++ " + curr_file_path + " -o " + exe_file_name
        result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=10)
        
        if result.returncode != 0:
            output = result.stderr.decode('utf-8')
        else:
            exe_file_path = os.path.abspath(exe_file_name)
            result = subprocess.run([exe_file_path], stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=5)
            output = result.stdout.decode('utf-8')
    except subprocess.CalledProcessError as e:
        output = e.output.decode('utf-8')
    except subprocess.TimeoutExpired:
        output = "Error: Code execution timed out."  
        
    return jsonify({'output': output})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
