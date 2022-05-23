import 'package:facebook_clone_flutter/config/palette.dart';
import 'package:facebook_clone_flutter/data/data.dart';
import 'package:flutter/material.dart';
import 'package:facebook_clone_flutter/widgets/widgets.dart';
import 'package:material_design_icons_flutter/material_design_icons_flutter.dart';
import 'package:facebook_clone_flutter/screens/screens.dart';

class HomeScreen extends StatelessWidget {
  // const HomeScreen({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 6,
      child: Scaffold(
        body: CustomScrollView(
          slivers: [
            SliverAppBar(
              // brightness: Brightness.light,
              backgroundColor: Colors.white,
              title: Text(
                'facebook',
                style: TextStyle(
                  color: Palette.facebookBlue,
                  fontSize: 28,
                  fontWeight: FontWeight.bold,
                  letterSpacing: -0.9,
                ),
              ),
              floating: true,
              actions: [
                CircleButton(
                  icon: Icons.add,
                  iconSize: 30,
                  onPressed: () => Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => CreatePostScreens(),
                    ),
                  ),
                ),
                CircleButton(
                  icon: Icons.search,
                  iconSize: 30,
                  onPressed: () => print('Search Button'),
                ),
                CircleButton(
                  icon: MdiIcons.facebookMessenger,
                  iconSize: 30,
                  onPressed: () => print('Messenger Button'),
                ),
              ],
            ),
            SliverToBoxAdapter(
              child: CreatePostContainer(currentUser: currentUser),
            ),
          ],
        ),
      ),
    );
  }
}
