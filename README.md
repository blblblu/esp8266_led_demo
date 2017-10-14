# ESP8266 LED Demo

This is a little example to show how to remote control an ESP8266 over wifi with your smartphone.

[![demo video](https://img.youtube.com/vi/CBABLYRuyJc/0.jpg)](https://www.youtube.com/watch?v=CBABLYRuyJc)

The [Arduino code](esp8266_server/main.ino) creates a web server which reacts to the routes `http://[url]/on` `http://[url]/off` which will turn a connected led on and off respectively.

The [smartphone app](flutter_app/lib/main.dart) consists of an input field for the url/ip address of your ESP and two buttons to turn your led on or off by requesting the corresponding url.
