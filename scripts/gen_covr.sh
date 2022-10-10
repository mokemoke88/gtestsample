#!/bin/bash

## カバレッジレポート出力用スクリプト
##
## 事前条件
##  カバレッジデータ(*.gcda, *gcno)を出力していること.
## TODO :

set -e

TARGET_TEST=source/test/service.test
TARGET_OBJDIR=source/test/CMakeFiles/service.test.dir/__/service
TARGET_SRCDIR=../source/service
## note. TARGET_SRCDIR からの相対パス もしくは絶対パス
OUTDIR=../../coverage-report

${TARGET_TEST}

cp ${TARGET_OBJDIR}/*.gcda ${TARGET_SRCDIR}
cp ${TARGET_OBJDIR}/*.gcno ${TARGET_SRCDIR}

cd ${TARGET_SRCDIR}

#gcov -bc -p -l *.gcda
#gcov -bc -p -l *.gcno

mkdir -p ${OUTDIR}
gcovr --gcov-executable gcov-11 -r . --html --html-details -o ${OUTDIR}/index.html
# gcovr -g -r . --html --html-details -o ${OUTDIR}/index.html
# rm -rf *.gcda *.gcno *.gcov
