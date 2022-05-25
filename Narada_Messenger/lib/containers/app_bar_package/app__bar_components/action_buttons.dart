import 'package:flutter/material.dart';

enum Menu { itemOne, itemTwo, itemThree, itemFour }

List<Widget> appBarActionButtons = [
  PopupMenuButton<Menu>(
    itemBuilder: (BuildContext context) => <PopupMenuEntry<Menu>>[
      const PopupMenuItem<Menu>(
        value: Menu.itemOne,
        child: Text('Settings'),
      ),
      const PopupMenuItem<Menu>(
        value: Menu.itemTwo,
        child: Text('Item 2'),
      ),
      const PopupMenuItem<Menu>(
        value: Menu.itemThree,
        child: Text('Item 3'),
      ),
      const PopupMenuItem<Menu>(
        value: Menu.itemFour,
        child: Text('Item 4'),
      ),
    ],
  ),
];
