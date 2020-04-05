package main

//dummy commit
import (
	"context"
	//"fmt"
	"log"
	"github.com/aws/aws-lambda-go/lambda"
	"github.com/aws/aws-lambda-go/events"
)

type MyEvent struct {
	Name string `json:"name"`
}

type MyResponse struct {
	Message string `json:"Response:"`
}

func HandleRequest(ctx context.Context, request events.APIGatewayProxyRequest) (events.APIGatewayProxyResponse, error) {
	//fmt.Printf("Processing request data for request %s.\n", request.RequestContext.RequestID)
	//fmt.Printf("Body size = %d.\n", len(request.Body))

	log.Println("Headers:")
	for key, value := range request.Headers {
		log.Printf("    %s: %s\n", key, value)
	}
	_, found := request.Headers["Authorization"]

	if !found {
		return events.APIGatewayProxyResponse{Body: "\"message\": \"unauthorized\"", StatusCode: 401}, nil
	}

	return events.APIGatewayProxyResponse{Body: request.Body, StatusCode: 200}, nil
}

func main() {
	lambda.Start(HandleRequest)
}
