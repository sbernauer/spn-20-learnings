### Run mariad inside docker:
docker run -d -p 127.0.0.1:3306:3306 -e MYSQL_ROOT_PASSWORD=Uu5ZyuXcQHLcMBQeC9Uih4AWjJuswM3SNCmNS8E8 mariadb/server


### Use utf8 character set for gameserver-table in mariadb


### Steps to compile & start
mysql -h 127.0.0.1 -u root -p

CREATE DATABASE snake CHARACTER SET = 'utf8';

Make sure website/Programmierspiel/local_settings.py and gameserver/src/Environment.h are copyed from this repo.

```
./dev_build.sh

cd gameserver/docker4bots
mkdir /mnt/spn_shm/
./00_setup_shm_for_test.sh
./0_build_spn_cpp_base.sh

cd ../..
./dev_run.sh
```

Look into helper_scripts/ngingx.conf that server_name and port are correct.
I have choosen port 26174 to be not crawled by others and 2fast4you2.de as server_name.
Normaly you can reach the server at port 3000.
