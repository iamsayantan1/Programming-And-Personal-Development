import 'package:chat/src/models/user.dart';
import 'package:chat/src/services/user/user_service_impl.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:rethinkdb_dart/rethinkdb_dart.dart';
import 'helpers.dart';

void main() {
  Rethinkdb r = Rethinkdb();
  Connection connection;
  UserService sut;

  setUp(() async {
    connection = await r.connect(host: "127.0.0.1", port: 28015);
    await createDb(r, connection);
    sut = UserService(connection, r);
  });

  tearDown(() async {
    await cleanDb(r, connection);
  });

  test('creates a new user document in database', () async {
    final user = User(
      userName: 'test',
      photoUrl: 'url',
      active: true,
      lastSeen: DateTime.now(),
      newId: 'id',
    );
    final userWithId = await sut.connect(user);
    expect(userWithId.id, isNotEmpty);
  });
}
