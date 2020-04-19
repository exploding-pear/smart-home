import boto3
import json
#dummy commit
def handler(event, context):
	print(type(event))
	print(type(context))
	return("{\"message\":\"hello world!\"}")