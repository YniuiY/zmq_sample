if [ -d build ]; then
 rm -r build
fi
DIR=`pwd`
echo $DIR

cd $DIR/proto
protoc *.proto --cpp_out $DIR/proto
echo "protoc over"

cd $DIR
mkdir build
cd build
cmake ..
make
