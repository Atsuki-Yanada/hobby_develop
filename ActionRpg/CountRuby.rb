#�w�肵���f�B���N�g���Ŏ��s����ꍇ�͉��̂悤�Ƀf�B���N�g���̃p�X������
#Dir.chdir("C:/Users/abc/Desktop/Ruby/Ex3")

#���f�B���N�g�����ɂ���S�Ă�*.cpp *.h �t�@�C������z��Ɋi�[
file = Dir.glob("*.cpp")
fileH = Dir.glob("*.h")
file.concat(fileH)    #�z��.concat ���\�b�h ��2�̔z���1�̔z��Ɍ�������
#�t�@�C������ϐ�var�ɑ�����āA�t�@�C���̍s�����J�E���g
total = 0 
file.each{|var|
	total += File.read(var).count("\n")
}
p total