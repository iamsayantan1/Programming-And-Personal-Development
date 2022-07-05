import 'package:flutter/material.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.symmetric(
        horizontal: 20,
        vertical: 15,
      ),
      child: Row(
        children: <Widget>[
          Container(
            padding: EdgeInsets.all(2),
            decoration: BoxDecoration(
              borderRadius: BorderRadius.all(Radius.circular(40)),
              border: Border.all(
                width: 2,
                color: Colors.green,
              ),
              // shape: BoxShape.circle,
              boxShadow: [
                BoxShadow(
                  color: Colors.grey.withOpacity(0.5),
                  spreadRadius: 2,
                  blurRadius: 5,
                ),
              ],
            ),
            child: const CircleAvatar(
              radius: 35,
              backgroundImage: AssetImage('assets/images/ironman.jpeg'),
              // backgroundColor: Colors.redAccent,
            ),
          ),
          Container(
            width: MediaQuery.of(context).size.width * 0.65,
            padding: EdgeInsets.only(left: 20),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(
                  'data',
                ),
                Text(
                  '12:30PM',
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
