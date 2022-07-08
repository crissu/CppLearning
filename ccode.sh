fileName=12.8_Queue
cd cpp_primer_plus_code
mkdir -p $fileName
cd $fileName
git clone git@github.com:cpprepos/simple-cpp-project.git
mv ./simple-cpp-project/* ./
rm -rf simple-cpp-project
echo "create project done"