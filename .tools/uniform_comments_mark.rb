# Yue Wang  Aug.2015
#   sub /// or //! to //
#   to use:
#     $ ruby uniform_comments_mark.rb dir extension

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
    line.sub! "///", "//"
    line.sub! "//!", "//"
  end
  File.open(path, 'w+'){ |file| file.puts content }
end
