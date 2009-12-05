
task :clean do
  sh "rm -f *.o"
end

rule '.o' => '.cpp' do |t|
  sh "g++ -I/opt/local/include #{t.source} -c -o #{t.name}"
end

%w(copy_constructors references auto_ptr boost_ptr).each do |exe|
  file exe => "#{exe}.o" do
    sh "g++ -I/opt/local/include -o #{exe} #{exe}.o"
  end
  task :all => exe
  task :clean do
    sh "rm -f #{exe}"
  end
end
