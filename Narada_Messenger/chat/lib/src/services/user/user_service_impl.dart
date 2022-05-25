import 'package:chat/src/models/user.dart';
import 'package:chat/src/services/user/user_service_contract.dart';

class UserService implements IUserService {
  @override
  Future<User> connect(User user) {
    // TODO: implement connect
    throw UnimplementedError();
  }

  @override
  Future<void> disconnect(User user) {
    // TODO: implement disconnect
    throw UnimplementedError();
  }

  @override
  Future<List<User>> online() {
    // TODO: implement online
    throw UnimplementedError();
  }

}