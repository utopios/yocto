DESCRIPTION = "Our first recipes hello"
SECTION = "examples"
LICENSE = "MIT"
SRC_URI = "file://hello.c"

do_fetch() {
	# fetch sources from SRC_URI uatomatically
	:
}

do_unpack() {
	:
}
do_compile() {
	${CC} hello.c -o hello
}
do_install() {
	install -m 0755 hello ${D}${bindir}/hello
}

