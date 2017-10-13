import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  runApp(new LedDemoApp());
}

class LedDemoApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return new MaterialApp(
      title: 'LED Demo',
      theme: new ThemeData(
        primarySwatch: Colors.teal,
      ),
      home: new HomePage(title: 'LED Demo'),
    );
  }
}

class HomePage extends StatefulWidget {
  HomePage({Key key, this.title}) : super(key: key);

  final String title;

  @override
  _HomePageState createState() => new _HomePageState();
}

class _HomePageState extends State<HomePage> {
  String _ip;

  void ledOn() {
    var httpClient = createHttpClient();
    httpClient.get("http://" + _ip + "/on");
  }

  void ledOff() {
    var httpClient = createHttpClient();
    httpClient.get("http://" + _ip + "/off");
  }

  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text(widget.title),
      ),
      body: new Container(
        padding: const EdgeInsets.all(16.0),
        child: new Column(
          children: <Widget>[
            new TextField(
              onChanged: (String ip) {
                setState(() {
                  _ip = ip;
                });
              },
            ),
            new Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: <Widget>[
                new IconButton(
                    onPressed: ledOn,
                    icon: new Icon(Icons.flash_on)),
                new IconButton(
                    onPressed: ledOff,
                    icon: new Icon(Icons.flash_off)),
              ],
            ),
          ],
        ),
      ),
    );
  }
}
