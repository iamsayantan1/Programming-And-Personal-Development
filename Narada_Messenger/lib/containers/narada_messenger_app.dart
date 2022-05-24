import 'package:flutter/material.dart';
import 'home_screen_container.dart';

class NaradaMessengerApp extends StatelessWidget {
  const NaradaMessengerApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Narada Messenger',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      debugShowCheckedModeBanner: false,
      home: HomeScreenContainer(),
    );
  }
}
