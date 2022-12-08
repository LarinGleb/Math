
echo "--------- Install gtest ---------"
sudo apt-get install libgtest-dev
cd /usr/src/googletest/googletest
sudo mkdir build && cd build
sudo cmake ..
sudo make
sudo make install
cd ..
rm -rf build