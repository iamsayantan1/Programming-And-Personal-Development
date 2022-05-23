import 'package:flutter/material.dart';

class CircleButton extends StatefulWidget {
  final IconData icon;
  final double iconSize;
  final Function onPressed;

  const CircleButton({
    Key? key,
    required this.icon,
    required this.iconSize,
    required this.onPressed,
  }) : super(key: key);

  @override
  State<CircleButton> createState() => _CircleButtonState();
}

class _CircleButtonState extends State<CircleButton>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(vsync: this);
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.all(6.0),
      decoration:
          BoxDecoration(color: Colors.grey[200], shape: BoxShape.circle),
      child: IconButton(
        icon: Icon(
          widget.icon,
        ),
        iconSize: widget.iconSize,
        color: Colors.black,
        onPressed: () {
          setState(() {
            widget.onPressed();
          });
        },
      ),
    );
  }
}
