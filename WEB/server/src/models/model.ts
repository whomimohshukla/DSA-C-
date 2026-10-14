
import mongoose, { Schema, model } from "mongoose";

export type TaskStatus = "pending" | "in-progress" | "completed";

export interface ITask {
  title: string;
  description?: string;
  status: TaskStatus;
  completed: boolean;
  createdAt: Date;
  updatedAt: Date;
}

const taskSchema = new Schema<ITask>(
  {
    title: {
      type: String,
      required: [true, "Title is required"],
      trim: true,
      minlength: 3,
      maxlength: 100
    },
    description: {
      type: String,
      trim: true,
      maxlength: 500
    },
    status: {
      type: String,
      enum: ["pending", "in-progress", "completed"],
      default: "pending"
    },
    completed: {
      type: Boolean,
      default: false
    }
  },
  {
    timestamps: true,
    versionKey: false
  }
);

export const Task = model<ITask>("Task", taskSchema);
