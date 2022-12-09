#include <ESP8266WiFi.h>

WiFiClient wifiClient;
const char *host = "projects.benax.rw";

void setup()
{
    Serial.begin(115200);
    connectToWiFi("RCA-WiFi", "rca@2k19");
}

void loop()
{
    String mData = "";
    String device = "CaRiMount-Device";
    String temperature = "32 C";
    String humidity = "23";
    String heat_index = "13";
    mData = "device=" + device + "&temperature=" + temperature + "&humidity=" + humidity + "&heat_index=" + heat_index;
    connectToHost(80);
    transferData(mData, "/f/o/r/e/a/c/h/p/r/o/j/e/c/t/s/2a3a671bcd46e96952ddb5de8f43a654/Charles_IoT_Project/backend.php/");
    delay(5000);
}
// https://projects.benax.rw/f/o/r/e/a/c/h/p/r/o/j/e/c/t/s/2a3a671bcd46e96952ddb5de8f43a654/Charles_IoT_Project/backend.php
void connectToWiFi(const char *ssid, const char *passwd)
{
    WiFi.mode(WIFI_OFF); // This prevents reconnection issue
    delay(10);
    WiFi.mode(WIFI_STA);      // This hides the viewing of ESP as wifi hotspot
    WiFi.begin(ssid, passwd); // Connect to your WiFi router
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.print(".");
    }
    Serial.println();
}

void connectToHost(const int httpPort)
{
    int retry_counter = 0;        // To be used while retrying to get connected
    wifiClient.setTimeout(15000); // 15 Seconds
    delay(1000);
    Serial.printf("Connecting to \"%s\"\n", host);

    while ((!wifiClient.connect(host, httpPort)) && (retry_counter <= 30))
    {
        delay(100);
        Serial.print(".");
        retry_counter++;
    }

    if (retry_counter == 31)
    {
        Serial.println("\nConnection failed.");
        return;
    }
    else
    {
        Serial.printf("Connected to \"%s\"\n", host);
    }
}

void transferData(String data, const char *filepath)
{
    Serial.println("Transferring data... ");
    bool isWiFiAvailable = wifiClient.available();
    Serial.println(isWiFiAvailable);
    wifiClient.println("POST " + (String)filepath + " HTTP/1.1");
    wifiClient.println("Host: " + (String)host);
    wifiClient.println("User-Agent: ESP8266/1.0");
    wifiClient.println("Content-Type: application/x-www-form-urlencoded");
    wifiClient.println("Content-Length: " + (String)data.length());
    wifiClient.println();
    wifiClient.print(data);
    getFeedback("Success");
}

/*
 * GET FEEDBACK
 */
void getFeedback(String success_msg)
{
    String datarx;
    while (wifiClient.connected())
    {
        String line = wifiClient.readStringUntil('\n');
        if (line == "\r")
        {
            break;
        }
    }
    while (wifiClient.available())
    {
        datarx += wifiClient.readStringUntil('\n');
    }
    Serial.println(datarx);
    if (datarx.indexOf(success_msg) >= 0)
    {
        Serial.println("Data Transferred.\n");
    }
    else
    
    {
        Serial.println("Data Transfer Failed.\n");
    }
    datarx = "";
}