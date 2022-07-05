import 'package:chat/src/models/user.dart';
import 'package:chat/src/services/user/user_service_contract.dart';
import 'package:rethinkdb_dart/rethinkdb_dart.dart';

class UserService implements IUserService {
  final Connection _connection;
  final Rethinkdb r;

  UserService(this._connection, this.r);

  @override
  Future<User> connect(User user) async {
    // TODO: implement connect
    var data = user.toJson();
    if (user.id != null) {
      data['id'] = user.id;
    }

    final result = await r.table('users').insert(data).run(_connection);

    return User.fromJson(result['changes'].first['new_val']);
    // throw UnimplementedError();
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
