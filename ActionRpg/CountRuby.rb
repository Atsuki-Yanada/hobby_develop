#指定したディレクトリで実行する場合は下のようにディレクトリのパスを書く
#Dir.chdir("C:/Users/abc/Desktop/Ruby/Ex3")

#同ディレクトリ内にある全ての*.cpp *.h ファイル名を配列に格納
file = Dir.glob("*.cpp")
fileH = Dir.glob("*.h")
file.concat(fileH)    #配列名.concat メソッド は2つの配列を1つの配列に結合する
#ファイル名を変数varに代入して、ファイルの行数をカウント
total = 0 
file.each{|var|
	total += File.read(var).count("\n")
}
p total