import 'package:flutter/material.dart';
import '../screens/home_screen.dart';
import 'app_bar_package/app_bar_package.dart';

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
    HomeScreen(),
    Center(child: Text('Story', style: TextStyle(fontSize: 72))),
    Center(child: Text('People', style: TextStyle(fontSize: 72))),
    Center(child: Text('Meet', style: TextStyle(fontSize: 72))),
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // extendBody: true,
      backgroundColor: Colors.white,
      appBar: appBar,
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
