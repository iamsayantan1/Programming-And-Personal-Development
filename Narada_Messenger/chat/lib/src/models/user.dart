import 'package:flutter/foundation.dart';

class User {
  String get id => _id;
  String userName;
  String photoUrl;
  String _id;
  bool active;
  DateTime lastSeen;

  User({
    required String userName,
    required String photoUrl,
    required bool active,
    required DateTime lastSeen,
  });

  toJson() => {
        'userName': userName,
        'photoUrl': photoUrl,
        'active': active,
        'lastSeen': lastSeen,
      };

  factory User.fromJson(Map<String, dynamic> json) {
    final user = User(
      userName: json['userName'],
      photoUrl: json['photoUrl'],
      active: json['active'],
      lastSeen: json['lastSeen'],
    );
    user._id = json['id'];
    return user;
  }
}
