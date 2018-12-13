package main

import (
	"os/exec"

	"github.com/usthooz/oozlog/go"
)

func main() {
	c := "echo hello world"
	cmd := exec.Command("sh", "-c", c)
	err := cmd.Run()
	ozlog.Infof("err: %v", err)
}
