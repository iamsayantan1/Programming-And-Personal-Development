import 'package:flutter/material.dart';

Container appBarDecoration = Container(
  decoration: BoxDecoration(
    gradient: LinearGradient(
      begin: Alignment.topLeft,
      end: Alignment.bottomRight,
      colors: <Color>[
        Colors.red,
        Colors.blue,
        Colors.green,
        Colors.yellow,
      ],
    ),
  ),
);
