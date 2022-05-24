import 'package:flutter/material.dart';
import 'package:narada_messenger/style/style.dart';

class HomeScreenContainer extends StatefulWidget {
  const HomeScreenContainer({Key? key}) : super(key: key);

  @override
  State<HomeScreenContainer> createState() => _HomeScreenContainerState();
}

class _HomeScreenContainerState extends State<HomeScreenContainer> {
  int index = 0;

  // final screens = [
  //   HomeScreen(),
  //   //   SearchScreen(),
  //   //   FavouriteScreen(),
  //   //   SettingsScreen(),
  //   //   ProfileScreen(),
  // ];

  final screens = [
    Center(child: Text('Chat', style: TextStyle(fontSize: 72))),
    Center(child: Text('Story', style: TextStyle(fontSize: 72))),
    Center(child: Text('People', style: TextStyle(fontSize: 72))),
    Center(child: Text('Meet', style: TextStyle(fontSize: 72))),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // extendBody: true,
      backgroundColor: Colors.white,
      appBar: AppBar(
        title: appName,
        elevation: 5,
        centerTitle: false,
        flexibleSpace: Container(
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
        ),
        actions: [
          IconButton(onPressed: () {}, icon: Icon(Icons.bubble_chart_outlined))
        ],
      ),
      body: screens[index],
      bottomNavigationBar: NavigationBarTheme(
        data: NavigationBarThemeData(
          indicatorColor: Colors.blue.shade100,
          labelTextStyle: MaterialStateProperty.all(
            TextStyle(
              fontSize: 14,
              fontWeight: FontWeight.w500,
            ),
          ),
        ),
        child: NavigationBar(
          height: 60,
          backgroundColor: Colors.grey.shade100,
          selectedIndex: index,
          animationDuration: Duration(milliseconds: 1000),
          onDestinationSelected: (index) => setState(() => this.index = index),
          destinations: [
            NavigationDestination(
              icon: Icon(Icons.chat_outlined),
              label: 'Chat',
            ),
            NavigationDestination(
              icon: Icon(Icons.track_changes),
              label: 'Story',
            ),
            NavigationDestination(
              icon: Icon(Icons.group_outlined),
              label: 'People',
            ),
            NavigationDestination(
              icon: Icon(Icons.videocam_outlined),
              label: 'Meet',
            ),
          ],
        ),
      ),
    );
  }
}
