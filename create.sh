foldername=$1
echo "$foldername created"
git clone git@github.com:cpprepos/simple-cpp-project.git
cd simple-cpp-project
rm -rf .git
cd ../
mkdir -p $foldername
cp simple-cpp-project/* $foldername -r
rm -rf simple-cpp-project
