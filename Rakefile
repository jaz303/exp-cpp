
task :clean do
  sh "rm -f *.o"
end

rule '.o' => '.cpp' do |t|
  sh "g++ #{t.source} -c -o #{t.name}"
end

%w(copy_constructors references).each do |exe|
  file exe => "#{exe}.o" do
    sh "g++ -o #{exe} #{exe}.o"
  end
  task :all => exe
  task :clean do
    sh "rm -f #{exe}"
  end
end
