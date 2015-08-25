# Yue Wang Aug.2015
# change #include<iostream> to #include <iostream>
# to use
#   $ ruby insert_space_in_include.rb dir extension

if ARGV.size != 2
  puts "wrong argumens"
  exit
end

dir = ARGV[0]
extension = ARGV[1]

paths = Dir.glob "#{ dir }/**/*.#{ extension }"
paths.each do |path|
  content = File.readlines path
  content.each do |line|
    #check if it's something like "#include<iostream>"
    if line.include?('#') and line.split(' ').size == 1
      line.sub! "#include", "#include "
    end
  end
  File.open(path, 'w+'){ |file| file.puts content }
end
