### Run mariad inside docker:
docker run -d -p 4306:3306 -e MYSQL_ROOT_PASSWORD=snake mariadb/server


### Use utf8 character set for gameserver-table in mariadb

CREATE DATABASE snake
  CHARACTER SET = 'utf8';
