// Fill in  your WiFi networks SSID and password
#define SECRET_SSID "example wifi"
#define SECRET_PASS "example-pass"

// Fill in the hostname of your AWS IoT broker
#define SECRET_BROKER "example-aws-broker.amazonaws.com"

// Fill in the boards public certificate
const char SECRET_CERTIFICATE[] = R"(
-----BEGIN CERTIFICATE-----
CERTIFICATE DOWNLOADED FROM AWS
-----END CERTIFICATE-----
)";
