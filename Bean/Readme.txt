Bean補足資料ファイルです。


ファイル構成
	api
		Beanでデフォルトで使用出来るクラスライブラリです。
		ただしapi/test はデバッグ用のソース群です。
		
	License
		Beanで使用したライブラリのライセンスです。
		
	TestCode
		Beanでデバッグに使用していたソースコードです。
		どのようなコードが実行出来るかのサンプルとして一応置いています。
		
	SampleCode
		実際にBeanで書いたプログラムのサンプルです。
		
	Bean.exe
		これを使用してプログラムを実行します。
		使用出来る引数は 言語仕様.text を参照してください。
		
	Docclass.bat
		Bean doc api.String を引数として Bean.exe を起動します。
		
	Dumpmain.bat
		Bean dump main.bn を引数として Bean.exe を起動します。
		
	REPL.bat
		Bean repl を引数として Bean.exe を起動します。
		
	Runmain.bat
		Bean bean main.bn を引数として Bean.exe を起動します。
		
	icu~.dll
		Bean.exe の起動に必要な ICUライブラリ です。
		
	sys.ini
		Beanの設定情報を格納するファイルです。
		存在しない場合には自動生成されます。