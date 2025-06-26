
import sys 
import json 
import os 

# add lidb to sys path
config_path = os.path.join(os.getcwd(), "pkg", "config.json")

file = open( config_path, 'r')

data = json.load(file)

sys.path.append(data['lidb'])

file.close() 