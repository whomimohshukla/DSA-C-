import type { Request, Response, NextFunction } from "express";

import { Task } from "../models/model";

export async function createTask(
	req: Request,
	res: Response,
	next: NextFunction,
) {
	try {
		const { title, description } = req.body;

        


	} catch {
		res.status(400).json({ message: "Invalid request body" });
	}
}
