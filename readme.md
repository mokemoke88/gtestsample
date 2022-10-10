# Google Test Sample

## これはなに?

Google Test | Mock を使用する際のソースツリーサンプル

## ツリー構成

```
+- .devcontainer : vscode Dev Container 拡張向けの設定周り
+- include       : ヘッダディレクトリ
 +- service
+- source        : ソースコードディレクトリ
 +- service      : テスト対象ソースコード
+- test          : テストコードディレクトリ
 +- main.cc      : テストエントリポイント
 +- test-case001.cc : テストケースコード
+- third-party 
 +- googletest   : Google Test レポジトリクローン 
```


## 備忘録

### Dockerfile

#### tzdata パッケージインストール時の停止対応

tzdataパッケージインストール時にタイムゾーン等々の選択で処理がブロックするため
apt install を行う前に以下を追加

```Dockerfile
ENV DEBIAN_FRONTEND=noninteractive

```

もしくは

```Dockerfile
ENV TZ=Asia/Tokyo
```

### git

クローン後

```sh
git submodule update --init --recursive
```

もしくはクローン時に

```
git clone --recursive xxxx
```

コンテナを再生成した場合にコンテナ内でgitを使用するためには, 以下の実行が必要

```sh
git config --global --add safe.directory /workspaces/gtestsample
```

third-party 以下に googletest を submodule として取り込み

```sh
cd third-party
git submodule add https://github.com/google/googletest.git googletest
```

### build-essential で導入されるパッケージ

```
binutils
binutils-common
binutils-x86-64-linux-gnu
build-essential
bzip2
cpp
cpp-11
dirmngr
dpkg-dev
fakeroot
fontconfig-config
fonts-dejavu-core
g++
g++-11
gcc
gcc-11
gcc-11-base
gnupg
gnupg-l10n
gnupg-utils
gpg
gpg-agent
gpg-wks-client
gpg-wks-server
gpgconf
gpgsm
libalgorithm-diff-perl
libalgorithm-diff-xs-perl
libalgorithm-merge-perl
libasan6
libassuan0
libatomic1
libbinutils
libbrotli1
libbsd0
libc-dev-bin
libc-devtools
libc6-dev
libcc1-0
libcrypt-dev
libctf-nobfd0
libctf0
libdeflate0
libdpkg-perl
libexpat1
libfakeroot
libfile-fcntllock-perl
libfontconfig1
libfreetype6
libgcc-11-dev
libgd3
libgdbm-compat4
libgdbm6
libgomp1
libisl23
libitm1
libjbig0
libjpeg-turbo8
libjpeg8
libksba8
libldap-2.5-0
libldap-common
liblocale-gettext-perl
liblsan0
libmd0
libmpc3
libmpfr6
libnpth0
libnsl-dev
libperl5.34
libpng16-16
libquadmath0
libreadline8
libsasl2-2
libsasl2-modules
libsasl2-modules-db
libsqlite3-0
libstdc++-11-dev
libtiff5
libtirpc-dev
libtsan0
libubsan1
libwebp7
libx11-6
libx11-data
libxau6
libxcb1
libxdmcp6
libxpm4
linux-libc-dev
lto-disabled-list
make
manpages
manpages-dev
netbase
patch
perl
perl-modules-5.34
pinentry-curses
readline-common
rpcsvc-proto
ucf
xz-utils
```
