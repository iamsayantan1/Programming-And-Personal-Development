// import 'package:flutter/foundation.dart';

class User {
  String get id => newId;
  String userName;
  String photoUrl;
  String newId;
  bool active;
  DateTime lastSeen;

  User({
    required this.userName,
    required this.photoUrl,
    required this.active,
    required this.lastSeen,
    required this.newId,
  });

  toJson() => {
        'userName': userName,
        'photoUrl': photoUrl,
        'active': active,
        'lastSeen': lastSeen,
      };

  factory User.fromJson(Map<String, dynamic> json) {
    final user = User(
      newId: json['newId'],
      userName: json['userName'],
      photoUrl: json['photoUrl'],
      active: json['active'],
      lastSeen: json['lastSeen'],
    );
    user.newId = json['id'];
    return user;
  }
}
