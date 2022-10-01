import 'package:flutter/material.dart';
import './quiz.dart';
import './result.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return _MyAppState();
    // throw UnimplementedError();
  }
}

class _MyAppState extends State<MyApp> {
  final _questions = const [
    {
      'questionText': 'what\'s your favourite color?',
      'answers': [
        {'text': 'black', 'score': 10},
        {'text': 'red', 'score': 20},
        {'text': 'blue', 'score': 50},
        {'text': 'green', 'score': 45}
      ]
    },
    {
      'questionText': 'what\'s your favourite animal?',
      'answers': [
        {'text': 'kutta', 'score': 90},
        {'text': 'ghoda', 'score': 30},
        {'text': 'gaye', 'score': 40},
        {'text': 'makhi', 'score': 50}
      ]
    },
    {
      'questionText': 'what\'s your favourite movie?',
      'answers': [
        {'text': 'nahi dekhte', 'score': 100},
        {'text': '3 idiots', 'score': 10},
        {'text': 'your name', 'score': 90},
        {'text': 'dharma production', 'score': 0}
      ]
    },
  ];

  var _questionIndex = 0;
  var _totalScore = 0;

  void _resetQuiz() {
    setState(() {
      _questionIndex = 0;
      _totalScore = 0;
    });
  }

  void _answerQuestion(int score) {
    _totalScore = _totalScore + score;
    setState(() {
      _questionIndex = _questionIndex + 1;
    });
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('Yoi'),
        ),
        body: _questionIndex < _questions.length
            ? Quiz(
                answerQuestion: _answerQuestion,
                questionIndex: _questionIndex,
                questions: _questions,
              )
            : Result(_totalScore, _resetQuiz),
      ),
    );
  }
}
