import 'package:flutter/src/foundation/key.dart';
import 'package:flutter/src/widgets/framework.dart';
import 'package:flutter/material.dart';

class Result extends StatelessWidget {
  final int resultScore;
  final Function resetHandler;
  Result(this.resultScore, this.resetHandler);

  String get resultPhase {
    // getter
    var resultText = 'khatam yoi 👌🙌✨🎉💖';
    if (resultScore <= 30) {
      resultText = 'you are weird';
    } else if (resultScore <= 60) {
      resultText = 'you are likable';
    } else if (resultScore <= 100) {
      resultText = 'tum to ktai heavy driver ho';
    } else if (resultScore > 100) {
      resultText = 'you are awesome';
    }
    return resultText;
  }

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Column(
        children: <Widget>[
          Text(
            resultPhase,
            style: TextStyle(fontSize: 40, fontWeight: FontWeight.bold),
            textAlign: TextAlign.center,
          ),
          FlatButton(
            child: Text('Restart Quiz!'),
            textColor: Colors.blueAccent,
            onPressed: resetHandler,
          )
        ],
      ),
    );
  }
}
