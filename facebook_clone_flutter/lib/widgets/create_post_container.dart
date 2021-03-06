import 'package:cached_network_image/cached_network_image.dart';
import 'package:flutter/material.dart';
import 'package:facebook_clone_flutter/models/models.dart';

class CreatePostContainer extends StatelessWidget {
  final User currentUser;
  const CreatePostContainer({
    Key? key,
    required this.currentUser,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.fromLTRB(12, 8, 12, 0),
      color: Colors.white,
      child: Column(
        children: [
          Row(
            children: [
              CircleAvatar(
                radius: 20,
                backgroundColor: Colors.grey[200],
                backgroundImage:
                    CachedNetworkImageProvider(currentUser.imageUrl),
              ),
              const SizedBox(
                width: 8,
              ),
              const Expanded(
                child: TextField(
                  decoration: InputDecoration.collapsed(
                    hintText: 'What\'s on your mind?',
                  ),
                ),
              )
            ],
          ),
          const Divider(
            height: 10,
            thickness: 0.5,
          ),
          Row(
            children: [
              TextButton.icon(
                onPressed: () => print("FlatButton"),
                icon: const Icon(
                  Icons.videocam,
                  color: Colors.red,
                ),
                label: Text('Live'),
              ),
            ],
          ),
        ],
      ),
    );
  }
}
