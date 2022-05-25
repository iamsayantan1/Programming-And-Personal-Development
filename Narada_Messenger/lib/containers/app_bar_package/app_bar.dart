import 'package:flutter/material.dart';
import 'app__bar_components/app_bar_components.dart';

AppBar appBar = AppBar(
  title: appBarName,
  elevation: 5,
  centerTitle: false,
  flexibleSpace: appBarDecoration,
  actions: appBarActionButtons,
  foregroundColor: Colors.black,
);
