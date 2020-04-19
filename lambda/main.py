import boto3
import json

def handler(event, context):
	client = boto3.client('iot-data')

	for key in event.keys():
		print("{key}: {value}".format(key=key, value=event[key]))
	
	if not event['body']:
		message = json.loads('{"message": "missing status"}')
		return(message)

	body = json.loads(event['body'])
	if body['status'] == "on":
		response = client.publish(topic='arduino/incoming', qos=0, payload=b'{"status": "on"}')
		message = json.loads('{"message": "switch on"}')
	elif body['status'] == "off":
		message = json.loads('{"message": "switch off"}')
	else:
		message = json.loads('{"message": "invalid status"}')
	
	return(message)

	print(body['status'])

	return(message)